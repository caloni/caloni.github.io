function copy_clipboard(id) {
  var buttonCopy = " \\^ ctrl_c";
  var copyText = document.querySelector(id).textContent.substring(3);
  var afterTitle = copyText.search("\n");
  var afterHeader = copyText.search(buttonCopy);
  var title = copyText.substring(0, afterTitle);
  var header = copyText.substring(afterTitle + 1, afterHeader);
  var content = copyText.substring(afterHeader + buttonCopy.length + 1);

  content = content.replace(/(?:\r\n|\r|\n)/g, "\n\n");
  copyText = title + "\nWanderley Caloni, " + header + "\n\n" + content;
  navigator.clipboard.writeText(copyText);
}

