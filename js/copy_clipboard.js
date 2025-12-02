function copy_clipboard(id) {
  var copyText = document.querySelector(id).textContent.replace(/^\s+|\s+$/g, '');
  navigator.clipboard.writeText(copyText);
}
