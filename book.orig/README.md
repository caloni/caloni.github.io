# How to mount an EPUB

This guide is about how to manipulate an EPUB structure before repack its content. It will help you to know where to change references and indexes in the scheleton.

First, inside `EPUB` subfolder create a xhtml file for each chapter of appendix in your ebook. The files already written can be used as samples.

Then, inside the file `EPUB/package.opf`, add into the `<manifest>` section your file, like this:

```
<item id="mynewchapter" href="mynewchapter.xhtml" media-type="application/xhtml+xml"/>
```

In the same file, but into the `<spine>` section, add a reference to its id:

```
<itemref linear="yes" idref="mynewchapter"/>
```

Now, in the `EPUB/toc.ncx` file, add another reference to the file and the order it will appear in the ebook:

```
<navPoint playOrder="6" id="chap-6"><navLabel><text>My Chapter 6: Where I say something</text></navLabel><content src="mynewchapter.xhtml"/></navPoint>
```

Then, in the `EPUB/toc.xhtml` file, add... yes, another reference to the same file:

```
<p id="chap-6" class="toc"><a href="mynewchapter.xhtml"><strong><span class="font1">My Chapter 6:</span>&#160;&#160;&#160;&#160;&#160;I am sick of this</strong></a></p>
```

In the `EPUB/ncx.xhtml` you can insert a list of references into your file.

## Contents

```
<nav epub:type="toc">
<h2>Contents</h2>
<ol epub:type="list">
<li><a href="mynewchapter.xhtml">Chapter 6: What Is an Index?</a></li>
```

## Landmarks

```
<nav epub:type="landmarks">
<h2>Landmarks</h2>
<ol epub:type="list">
<li><a epub:type="cover" href="cover.xhtml">Cover</a></li>
<li><a epub:type="titlepage" href="titlepage.xhtml">Title Page</a></li>
<li><a epub:type="frontmatter" href="copyright.xhtml">Copyright</a></li>
<li><a epub:type="toc" href="toc.xhtml">Table of Contents</a></li>
<li><a epub:type="foreword" href="foreword001.xhtml">Foreword, by Dan Kirklin</a></li>
<li><a epub:type="introduction" href="introduction001.xhtml">Introduction</a></li>
<li><a epub:type="bodymatter" href="mynewchapter.xhtml">Chapter 6: Here I am again!</a></li>
```

## Page Navigation

```
<nav epub:type="page-list" hidden="">
<h2>Page Navigation</h2>
<ol epub:type="list">
<li class="section-label-rw" title="Inside cover"><a href="cover.xhtml#pia">Inside Cover</a></li>
<li class="section-label-rw" title="Title Page"><a href="titlepage.xhtml#pi">i</a></li>
<li class="section-label-rw" title="Copyright"><a href="copyright.xhtml#pii">ii</a></li>
<li class="section-label-rw" title="Table of Contents"><a href="toc.xhtml#piii">iii</a></li>
<li><a href="toc.xhtml#piv">iv</a></li>
<li class="section-label-rw" title="Foreword"><a href="foreword001.xhtml#pv">v</a></li>
<li><a href="foreword001.xhtml#pvi">vi</a></li>
<li><a href="foreword001.xhtml#pvii">vii</a></li>
<li><a href="foreword001.xhtml#pviii">viii</a></li>
<li class="section-label-rw" title="Introduction"><a href="introduction001.xhtml#pix">ix</a></li>
<li><a href="introduction001.xhtml#px">x</a></li>
<li class="section-label-rw" title="What Is an Index?"><a epub:type="bodymatter" href="mynewchapter.xhtml#p1">1</a></li>
<li><a epub:type="bodymatter" href="mynewchapter.xhtml#p2">2</a></li>
<li><a epub:type="bodymatter" href="mynewchapter.xhtml#p3">3</a></li>
<li><a epub:type="bodymatter" href="mynewchapter.xhtml#p4">4</a></li>
<li><a epub:type="bodymatter" href="mynewchapter.xhtml#p5">5</a></li>
<li><a epub:type="bodymatter" href="mynewchapter.xhtml#p6">6</a></li>
<li><a epub:type="bodymatter" href="mynewchapter.xhtml#p7">7</a></li>
<li><a epub:type="bodymatter" href="mynewchapter.xhtml#p8">8</a></li>
<li><a epub:type="bodymatter" href="mynewchapter.xhtml#p9">9</a></li>
<li><a epub:type="bodymatter" href="mynewchapter.xhtml#p10">10</a></li>
```

And finally, in the `EPUB/index.xhtml` file, insert all the splatered indexes around the book. For example:

```
<section epub:type="index-group" id="indexA">
<h3 class="groupletter">A</h3>
 <ul class="indexlevel1">
 <li epub:type="index-entry" class="indexhead1" id="mh6"><span epub:type="index-term">Alphabetization</span>. <span epub:type="index-xref-related" class="xreflist"><em>See also</em> <a epub:type="index-term" href="#mh160">Order</a></span>
  <ul class="indexlevel2">
  <li epub:type="index-entry" class="indexhead2" id="sh6.1"><span epub:type="index-term">of chemical indexes</span>, <span epub:type="index-locator-list" class="locatorlist"><a href="chapter002.xhtml#pinpt170">19</a></span>
  </li>
  <li epub:type="index-entry" class="indexhead2" id="sh6.2"><span epub:type="index-term">of first-line indexes</span>, <span epub:type="index-locator-list" class="locatorlist"><a href="chapter002.xhtml#pinpt145">18</a></span>
  </li>
  <li epub:type="index-entry" class="indexhead2" id="sh6.3"><span epub:type="index-term">systems of</span>, <span epub:type="index-locator-list" class="locatorlist"><a href="mynewchapter.xhtml#pinpt58">5&#8211;6</a></span>
  </li>
  </ul>
```

Note the `indexhead2`. This indicates multilevel indexes. Also, you can use the ids to reference to a specific point in your chapter. In the `mynewchapter` example it is pointing above to `#pinpt58`, which means there is a id like that in the text:

```
<p><a id="pinpt58"/>I am going to index this paragraph because its content is related to another points in the book.</p>
```

_Note: I believe we can incrementally adding references to the ebook create using blog post. We will see._
