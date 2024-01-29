function copy_clipboard(id) {
  var copyText = document.querySelector(id).textContent;
  if( copyText[0] == "\n" ) {
    copyText = copyText.substring(1);
  }
  if( copyText[0] == "#" ) {
    copyText = copyText.substring(2);
  }
  copyText = copyText.replace(" ^ ctrl_c","")
  copyText = copyText.replace(" [link]","")
  afterTitle = copyText.search("\n")
  if( afterTitle != -1 ) {
    copyText = copyText.slice(0, afterTitle) + "\nWanderley Caloni" + copyText.slice(afterTitle);
  }
  navigator.clipboard.writeText(copyText);
}

