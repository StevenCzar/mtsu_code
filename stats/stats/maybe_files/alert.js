$(document).ready(function() {
    function reqListener () {
        var xmlDoc;
        var alertText = '';
        if (window.DOMParser) {
            // code for modern browsers
            var parser = new DOMParser();
            xmlDoc = parser.parseFromString(this.responseText,"text/xml");
            alertText = xmlDoc.getElementsByTagName("item")[0].getElementsByTagName("description")[0].childNodes[0].nodeValue;
        } else {
            var junkText = encodeURIComponent(this.responseText);
            if (junkText.indexOf('MTSU ALERT') > -1) {
                alertText = junkText.substring(junkText.indexOf('MTSU ALERT'));
                if (alertText.indexOf('%3C') > -1) {
                    alertText = alertText.substring(0,alertText.indexOf('%3C'));
                }
                alertText = decodeURIComponent(alertText);
            }
        }

        if (alertText.indexOf('MTSU ALERT') > -1) {
            $('#alert-rave').append(alertText);
        }
    }

    var oReq = new XMLHttpRequest();
    oReq.addEventListener("load", reqListener);
    oReq.open("GET", "//www.getrave.com/rss/mtsu/channel1");
    oReq.send();
});
