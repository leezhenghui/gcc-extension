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
				"include"
			],
			'dependencies': [
				'instrument'
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
				"include"
			]
		}
	]
}
