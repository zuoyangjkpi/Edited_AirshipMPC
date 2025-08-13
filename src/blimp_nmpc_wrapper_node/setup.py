from setuptools import setup

package_name = 'blimp_nmpc_wrapper_node'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='eprice',
    maintainer_email='eprice@todo.todo',
    description='The blimp_nmpc_wrapper_node package',
    license='GPL-3.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'blimp_nmpc_wrapper_node = blimp_nmpc_wrapper_node.blimp_nmpc_wrapper_node:main',
        ],
    },
)
