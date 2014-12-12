r"""
Strip leading byte-order-mark from utf-8 files.
"""

def bomstrip(string):
  """
  Function to delete UTF-8 BOM character in "string"
  """
  import sys
  from binascii import hexlify

  if sys.version_info.major == 2:
      utf8bom = '\xef\xbb\xbf'
  elif sys.version_info.major == 3:
      utf8bom = b'\xef\xbb\xbf'
  else:
      raise 'This version of python is not supported.'

  if string[:3] == utf8bom:
    return(string[3:])
  else:
    return(string)
