import os
import zipfile

def zipdir(path, ziph):
  # ziph is zipfile handle
  paths = os.listdir(path)
  for p in paths:
    p = os.path.join(path, p) # Make the path relative
    if os.path.isdir(p): # Recursive case
      zipdir(p, ziph)
    else:
      ziph.write(p) # Write the file to the zipfile

with zipfile.ZipFile('caloni.epub', 'w', compression=zipfile.ZIP_STORED) as zipf:
  zipf.writestr("mimetype", "application/epub+zip")
with zipfile.ZipFile('caloni.epub', 'a', compression=zipfile.ZIP_DEFLATED, compresslevel=5) as zipf:
  zipdir('EPUB', zipf)
  zipdir('META-INF', zipf)

print('epub generated; to check epub run the command \'java -jar epubcheck.jar caloni.epub\'')
