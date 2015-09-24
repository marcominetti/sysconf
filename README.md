# sysconfx-next

Node bindings for sysconf(3), based on the sysconf module by Jen Andre
Some enhancements and port to node >= 0.11 by Alexander Vassilev

This readme is also based on the original version, but reflects the new APIs
```
sysconf - get configuration information at run time

#include <unistd.h>
long sysconf(int name);
```

## Installation

```
$ npm install sysconfx-next 
 ```

## Usage

### Example

```js

var sysconf = require('sysconfx-next');

// get clock ticks
console.log(sysconf(sysconf._SC_CLK_TCK)); // 100
//Compatible with original API
console.log(sysconf.get(sysconf._SC_CLK_TCK)); // 100
//Also possible to use a string, however it must be known to this module (must be a property of sysconf)
```
//List the known constants and their values for this system
//Note that the availability of each constant in the system's headers
//is tested when the module is installed (compile time), and only supported ones are
//available in JS. If you want to add a constant name to be recognized, you can add it
//to the keys object
console.log(JSON.stringify(sysconf.keys);

## License

MIT

