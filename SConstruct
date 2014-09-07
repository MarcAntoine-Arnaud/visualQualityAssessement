EnsureSConsVersion( 2, 3, 0 )

vqaVersionMajor = "0"
vqaVersionMinor = "0"
vqaVersionMicro = "1"

vqaVersion = [ vqaVersionMajor, vqaVersionMinor, vqaVersionMicro ]

vqaVersionStr = ".".join( vqaVersion )

buildMode = ARGUMENTS.get( 'mode', 'release' )
if not ( buildMode in [ 'debug', 'release' ] ) :
	raise Exception( "Can't select build mode ['debug', 'release']" )

env = Environment()

env.Append(
	CPPPATH = [
		'#src',
	],
	CXXFLAGS = [
		'-Wall',
		'-fPIC',
		'-std=c++0x',
		'-DVQA_VERSION_MAJOR=' + vqaVersionMajor,
		'-DVQA_VERSION_MINOR=' + vqaVersionMinor,
		'-DVQA_VERSION_MICRO=' + vqaVersionMicro,
	],
	LIBPATH = [
		'#src'
	],
	SHLIBVERSION = vqaVersionStr,
	)


Export( 'env' )

VariantDir( 'build/' + buildMode + '/src', 'src', duplicate = 0 )
VariantDir( 'build/' + buildMode + '/test', 'test', duplicate = 0 )

SConscript( 'src/SConscript', variant_dir = 'build/' + buildMode + '/src' )
SConscript( 'test/SConscript', variant_dir = 'build/' + buildMode + '/test' )
