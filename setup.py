from distutils.core import setup, Extension

module1 = Extension(
	'matrices',
	 sources = ['matr.c']
)

setup(
	name = 'matrices',
	version = '1.1.1',               
	description = 'zayob',
	ext_modules = [module1]
)