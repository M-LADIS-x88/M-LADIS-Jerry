from setuptools import find_packages
from setuptools import setup

setup(
    name='lidar_conversions',
    version='2.1.0',
    packages=find_packages(
        include=('lidar_conversions', 'lidar_conversions.*')),
)
