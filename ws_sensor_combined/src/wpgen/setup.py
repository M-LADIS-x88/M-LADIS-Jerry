from setuptools import setup

package_name = 'wpgen'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml'])
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='kfuher',
    maintainer_email='kfuher@umich.edu',
    description='Retrieve waypoint from ML and publish',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'ML_send_wp = wpgen.ML_send_wp:main',
        ],
        'colcon_core.package_identification': [
            'ros_package = colcon_ros.package_identification.ros:RosPackageIdentification'
        ]
    },
)

