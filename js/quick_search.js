$(function() {
  $("#quick_search").autocomplete({
    source: quick_search_posts,
  });
});

$(document).ready(function(){
  $('#quick_search').focus();
});

$(document).ready(function(){
    $("#quick_search").keypress(function(e){
    if(e.which == 13) {
            window.location = $(this).val();
        }
    });
});

$(document).ready(function(){
    $("#quick_search").change(function(){
      $("#quick_search_search_engine").attr("href", "https://duckduckgo.com/?q=site%3Acaloni.com.br" + "+" + $("#quick_search").val());
    });
});

