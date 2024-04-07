from setuptools import setup

package_name = 'wpgen'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        # ... keep the previously defined data_files ...
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
    },
)

