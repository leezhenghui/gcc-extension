{
	'includes': [ 'common.gypi' ],
		"targets": [
		{
			"target_name": "main",
			"product_name": "main",
			"type": "executable",
			"sources": [
				"./main.c",
			  "./startup_hook.c"
			],
			"cflags": [],
			"include_dirs": [
				"include",
		    './deps/simplelogger/simplog.h'	
			],
			'dependencies': [
				'instrument',
        './deps/simplelogger.gyp:simplelogger'
			],
			'configurations': {
			   'Debug': {
						"cflags": [
							"-finstrument-functions"
						]
					}	
			}
		},
		{
			"target_name": "instrument",
			"product_name": "instrument",
			'type': 'static_library',
			"sources": [
				"./instrument.c"
			],
			"cflags": [
			],
			"include_dirs": [
				"include",
		    './deps/simplelogger/simplog.h'	
			],
			'dependencies': [
        './deps/simplelogger.gyp:simplelogger'
			]
		},
		{
			"target_name": "preload_hook",
			"product_name": "preload_hook",
			'type': 'shared_library',
			"sources": [
				"./preload_hook.c"
			],
			"cflags": [
				 '-fPIC',
				 '-D_GNU_SOURCE'
			],
			'ldflags': [
			  '-shared'
			],
			"include_dirs": [
			],
			'link_settings': {
				'libraries': [
					'-ldl',
					'-nostartfiles'
					]	
			}
		}

	]
}
