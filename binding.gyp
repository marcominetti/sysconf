{
  "targets": [
  {
    "target_name": "sysconfx",
    "sources": [ "src/sysconf.cc" ],
    'include_dirs': [
        "<!(node -e \"require('nan')\")"
    ]
  }
  ]
}
