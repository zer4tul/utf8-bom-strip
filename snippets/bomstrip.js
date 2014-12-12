// A npm package named "strip-bom" is available for this purpose. Install it by:
// npm install --save strip-bom
// Source code at: https://github.com/sindresorhus/strip-bom

var stripBom = require('strip-bom');

stripBom('\ufeffFOO');
//=> FOO
