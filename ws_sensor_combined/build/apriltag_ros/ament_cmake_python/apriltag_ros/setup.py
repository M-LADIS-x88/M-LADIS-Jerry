from setuptools import find_packages
from setuptools import setup

setup(
    name='apriltag_ros',
    version='2.1.0',
    packages=find_packages(
        include=('apriltag_ros', 'apriltag_ros.*')),
)
