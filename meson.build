project('screwdriver', 'c',
	version : '0.1',
	default_options : ['c_std=c99', 'warning_level=2']
)

cc = meson.get_compiler('c')

raylib_deps = cc.find_library('raylib', required: true)
deps = [
	raylib_deps,
	cc.find_library('GL'),
	cc.find_library('m'),
	cc.find_library('pthread'),
	cc.find_library('dl'),
	cc.find_library('rt'),
	cc.find_library('X11')
]

srcs = [
	'main.c',
	'camera.c',
	'globals.c',
	'render.c',
	'screwdriver.c'
]

exe = executable('screwdriver', srcs,
	dependencies : deps,
	install : true
)
