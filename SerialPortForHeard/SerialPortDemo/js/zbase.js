
function getQmlChild(object, objName, bDeepIn) {
    for (let idx in object.children) {
        if (object.children[idx].objectName === objName) {
            return object.children[idx]
        }
    }

    if (bDeepIn && typeof object.children[idx].children !== 'undefined') {
        return getQmlChild(object.children[idx], objectName);
    }
}

function autoFit(obj, margin = 8) {
    var w = obj.parent.width
    var h = obj.parent.height
    obj.width = w - margin * 2
    obj.height = h - margin * 2
    obj.x = (w - obj.width) / 2
    obj.y = (h - obj.height) / 2
}

function autoAdjustView(obj, nSplit = 2) {
    var l = obj.parent.width / nSplit
    var t = obj.parent.height / nSplit
    var r = obj.parent.width - l
    var b = obj.parent.height - t

    if (obj.x > r) {
        obj.x = r
    }
    else if (obj.x + obj.width < l) {
        obj.x = l - obj.width
    }

    if (obj.y > b) {
        obj.y = b
    }
    else if (obj.y + obj.height < t) {
        obj.y = t - obj.height
    }
}







function calcAngle_xy(x, y) {
    if (x == 0) {
        return (y == 0 ? 0 : (y > 0 ? 90 : 270))
    }
    else if (y == 0) {
        return (x > 0 ? 0 : 180)
    }

    var angle = Math.atan(y / x) / Math.PI * 180

    // µÚ2¡¢3ÏóÏÞ
    if (x < 0) {
        angle += 180
    }

    // Adjust to [0, 360)
    if (angle < 0) {
        angle += 360
    }
    else if (angle >= 360) {
        angle -= 360
    }

    return angle
}

function calcAngle_2Points(pt1, pt2) {
    return calcAngle_xy(pt2.x - pt1.x, pt2.y - pt1.y)
}

// format("val: %s, %s, %s", 1, "abc", 3)
function format(str) {
    for (var i = 0; i < arguments.length - 1; i++) {
        str = str.replace("%s", arguments[i + 1]);
    }
    return str;
}

function expandStrLeft(str, len, ch = " ") {
    str = "" + str
    if (ch == "") {
        ch = " "
    }

    var n = len - str.length
    while (n > 0) {
        str = ch + str
        n -= ch.length
    }

    return str
}

function expandStrRight(str, len) {
    str = "" + str

    var n = len - str.length
    while (n > 0) {
        str = str + " "
        n--
    }

    return str
}



