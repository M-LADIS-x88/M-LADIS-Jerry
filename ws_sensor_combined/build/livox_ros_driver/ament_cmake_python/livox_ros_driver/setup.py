from setuptools import find_packages
from setuptools import setup

setup(
    name='livox_ros_driver',
    version='2.1.0',
    packages=find_packages(
        include=('livox_ros_driver', 'livox_ros_driver.*')),
)
