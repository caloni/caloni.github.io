function copy_clipboard(id) {
  var copyText = document.querySelector(id).textContent;
  if( copyText[0] == "\n" ) {
    copyText = copyText.substring(1);
  }
  copyText = copyText.replace(" ^ ctrl_c"," [by caloni]")
  copyText = copyText.replace(" [link]","")
  navigator.clipboard.writeText(copyText);
}

