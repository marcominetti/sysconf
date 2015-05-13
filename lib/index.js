var _sysconf = require('../build/Release/sysconfx.node');

/**
 * sysconf
 * @param {Number|String} param - sysconf param 
 *
 * @return {Number} value
 *
 */
var exports = module.exports = function(param) {
    if (typeof param === 'string') {
        var id = keys[param];
        if (id === undefined)
            throw new Error("Unknown sysconf constant '"+param+". Try with a numberic value");
        return _sysconf.sysconf(id);
    } else {
        return _sysconf.sysconf(param);
    }
}

exports.get = module.exports;
/**
    keys - a map of the known sysconf constant names and their values for this system
*/

var keys = exports.keys = _sysconf.keys();

for (var k in keys) {
  exports[k] = keys[k];
};
