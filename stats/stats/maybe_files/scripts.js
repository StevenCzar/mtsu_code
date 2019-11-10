var ssb = false;
var countMinute = 3;
//var countMinute = 10;

var sessionInterval;
var sessionLength = (countMinute*60*1000);
var countdownClock;
var secondTimer;
var metaHead = '';


$( document ).ready(function() {
    metaHead = document.title;
    windowScroll();
    $(window).scroll(function(){
        windowScroll();
    });

    $('#mobile-menu').on('click',function(){
        $(window).scrollTop(0);
        $('#side-menu').scrollTop(0);
        if ($('#side-menu').hasClass('show-mobile-menu')){
            $('#side-menu').removeClass('show-mobile-menu');
            $('#overlay').removeClass('show-mobile-menu');
        } else {
            $('#side-menu').addClass('show-mobile-menu');
            $('#overlay').addClass('show-mobile-menu');
        }
    });

    if ($('.portlet-column').length){
        buildCols();
    }

    $('#mnum-hide').on('click',function(){
        $('.mnum-display').addClass('hidden');
        $('#mnum-show').removeClass('hidden');
        $.post(root+'request/pipeline/hidemnum',{},function(){},'json');
    });
    $('#mnum-show').on('click',function(){
        $('.mnum-display').removeClass('hidden');
        $('#mnum-show').addClass('hidden');
        $.post(root+'request/pipeline/showmnum',{},function(){},'json');
    });
    $('#add-admin').on('click',function(){
        $.post(root+'request/pipeline/addadmin',{},function(data){
            if (data.success){
                window.location.href = window.location.href;
            } else {
                alert(data.error);
            }
        },'json');
    });
    $(document).on('click','.hide-outage',function(){
        $(this).parent('.outage-info').remove();
    });
    $('#remove-admin').on('click',function(){
        $.post(root+'request/pipeline/removeadmin',{},function(data){
            if (data.success){
                window.location.href = window.location.href;
            } else {
                alert(data.error);
            }
        },'json');
    });
    $('#extend-session').add('#timeout-overlay').on('click',function(){
        $.post(root+'request/pipeline/extendSession',{},function(data){
            if (data.success){
                countdownClock = (sessionLength/1000)+10;
                kickoff();
            } else {
                alert(data.error);
                window.location.href = window.location.href;
            }
        },'json');
    });

    kickoff();
});

function windowScroll() {
    //Add/remove logo from quicklinks
    if ($(window).scrollTop() > 50) {
        $('#mtsu-logo').addClass('logo-scroll');

    } else {
        $('#mtsu-logo').removeClass('logo-scroll');
    }

    if (($('#content-container').offset().top - $(window).scrollTop()) < $('#mtsu-quicklinks').outerHeight()){
        if (!$('#side-menu').hasClass('fixed-menu')){
            $('#side-menu').addClass('fixed-menu');
        }
    } else {
        $('#side-menu').removeClass('fixed-menu');
    }
}

function buildCols() {
    var col1 = 0;
    var col2 = 0;
    if ($('.portlet-icons').length) {
        col2 = $('.portlet-icons').outerHeight(true);
    }

    $('.portlet').each(function(){
        if(col1 <= col2 || $(this).data('left')) {
            col1 += $(this).outerHeight(true);
            $('#portlet-column-1').append($(this).clone());
        } else {
            col2 += $(this).outerHeight(true);
            $('#portlet-column-2').append($(this).clone());
        }
        $(this).addClass('portlet-original');
    });
}

function kickoff() {
    clearTimeout(secondTimer);
    clearTimeout(sessionInterval);
    if(countdownClock < sessionLength/1000) {
        countdownClock = sessionLength/1000;
    }
    document.title = metaHead;
    $('#timeout-overlay').hide();
    $('#timeout-content').hide();
    sessionInterval = setTimeout(checkRemaining,sessionLength);
}

function checkRemaining() {
    clearTimeout(sessionInterval);
    $.post(root+'request/pipeline/remainingSessionTime',{ssb:ssb},function(data){
        if (data.success){
            var remain = parseInt(data.remaining);
            if (remain < (countMinute*60)+10){
                countdownClock = remain;
                tickTock();
                if (remain > 10) {
                    sessionInterval = setTimeout(checkRemaining,(30*1000));//every 30 seconds
                } else {
                    sessionInterval = setTimeout(checkRemaining,1000);//every second
                }
            } else if (remain < (2*countMinute*60)+10) {
                sessionInterval = setTimeout(checkRemaining,(60*1000));//every minute
            } else {
                kickoff();
            }
        } else {
            $('#logout').click();
        }
    },'json');
}

function tickTock() {
    $('#timeout-overlay').show();
    $('#timeout-content').show();

    clearTimeout(secondTimer);
    if ((countdownClock*1000) > sessionLength) {
        kickoff();
        return;
    }
    if (countdownClock > 0) {
        var min = Math.floor(countdownClock/(60));
        var sec = countdownClock-(min*60);
        countdownClock--;
        document.title = '('+min+':'+('0'+sec).slice(-2)+') '+metaHead;
        $('#timeout-remaining').html(min+':'+('0'+sec).slice(-2));
        secondTimer = setTimeout(tickTock,1000);
    } else {
        $('#logout').click();
    }
}
