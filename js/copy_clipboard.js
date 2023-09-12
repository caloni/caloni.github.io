function copy_clipboard(id) {
  var copyText = document.querySelector(id).textContent;
  copyText = copyText.replace(" ^ ctrl_c","")
  copyText = copyText.replace(" [link]","")
  navigator.clipboard.writeText(copyText);
}

