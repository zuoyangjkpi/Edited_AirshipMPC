from setuptools import find_packages
from setuptools import setup

setup(
    name='neural_network_detector',
    version='0.0.0',
    packages=find_packages(
        include=('neural_network_detector', 'neural_network_detector.*')),
)
