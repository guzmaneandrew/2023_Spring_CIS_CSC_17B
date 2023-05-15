/*
 * Modified from https://www.w3schools.com/js/js_cookies.asp
 * Dr. Mark E. Lehr
 * 
 */

function setCookie(cname, cvalue, exdays) {
    //Create Date object to determine when cookie will expire
    var d = new Date();
    d.setTime(d.getTime() + (exdays * 24 * 60 * 60 * 1000));
    var expires = "expires="+d.toUTCString();
    //Add together the cookie name, cookie value, and expires string
    document.cookie = cname + "=" + cvalue + ";" + expires + ";path=/";
}

function getCookie(cname) {
  //Create variable with text to search for
  let name = cname + "=";
  //Decode the cookie string
  let decodedCookie = decodeURIComponent(document.cookie);
  //Split cookie on semicolons into an array ca
  let ca = decodedCookie.split(';');
  //Loop through ca array and read out each value
  for(let i = 0; i <ca.length; i++) {
    let c = ca[i];
    while (c.charAt(0) == ' ') {
      c = c.substring(1);
    }
    //If cookie is found, return value of the cookie
    if (c.indexOf(name) == 0) {
      return c.substring(name.length, c.length);
    }
  }
  //If cookie is not found, return ""
  return "";
}

function checkCookie() {
  let username = getCookie("username");
  //If cookie is set, display greeting
  if (username != "") {
   alert("Welcome again " + username);
  //If cookie not set, display a prompt box and store cookie using setCookie function
  } else {
    username = prompt("Please enter your name:", "");
    if (username != "" && username != null) {
      setCookie("username", username, 365);
    }
  }
}

//function checkCookie(cname) {
//    var value = getCookie(cname);
//    //If cookie is set, display greeting
//    if (value != "") {
//        alert("Cookie Name = " + cname + "Value = " + value);
//    //If cookie not set, display a prompt box and store cookie using setCookie function
//    } else {
//        value = prompt("Please enter your cookie :"+cname+" Value", "");
//        if (value != "" && value != null) {
//            setCookie(cname, value, 365);
//        }
//    }
//}