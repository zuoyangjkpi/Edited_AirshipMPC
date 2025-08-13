from setuptools import setup, find_packages
import os
from glob import glob

package_name = 'blimp_nmpc_wrapper_node'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # Install launch files
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
        # Install node files
        (os.path.join('share', package_name, 'nodes'), glob('nodes/*.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='eprice',
    maintainer_email='eprice@example.com',
    description='NMPC wrapper node for blimp control',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'blimp_nmpc_wrapper_node = blimp_nmpc_wrapper_node.blimp_nmpc_wrapper_node:main',
        ],
    },
)
