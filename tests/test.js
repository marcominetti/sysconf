
var sysconf = require('../lib/index.js');

console.log("Sysconf version:", sysconf(sysconf._SC_VERSION));
console.log("Clock ticks per second:", sysconf("_SC_CLK_TCK"));
//backward compat
var pageSize = sysconf.get(sysconf._SC_PAGE_SIZE)/1024;
console.log("Memory page size: ", pageSize, "kB");
console.log("Total Physical Memory: ",
            (sysconf(sysconf._SC_PHYS_PAGES) * pageSize), "kB");
console.log("Known sysconf constant names:\n"+JSON.stringify(sysconf.keys));
