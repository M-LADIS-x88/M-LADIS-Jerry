from setuptools import find_packages
from setuptools import setup

setup(
    name='lidar_slam',
    version='2.1.0',
    packages=find_packages(
        include=('lidar_slam', 'lidar_slam.*')),
)
