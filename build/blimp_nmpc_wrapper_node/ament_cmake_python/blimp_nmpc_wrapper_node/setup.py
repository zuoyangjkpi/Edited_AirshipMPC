from setuptools import find_packages
from setuptools import setup

setup(
    name='blimp_nmpc_wrapper_node',
    version='0.0.0',
    packages=find_packages(
        include=('blimp_nmpc_wrapper_node', 'blimp_nmpc_wrapper_node.*')),
)
