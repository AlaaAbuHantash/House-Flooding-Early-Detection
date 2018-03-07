# House-Flooding-Early-Detection
House Flooding Early Detection

The objective of this project is to inform the person about the occurrence of flooding immediately in order to take appropriate action quickly.

There are two parts in software design:
1. Web Server (done by Alaa Abu-Hantash):
We have created the web server in order to use it as a link between the device and the Android application. This web server has the database which includes ID and the current distaste for the water in a specified house. We have used phpmyadmin to create the database.

2. Android Application (done by Abrar Al-Taj):
We have built this application, it required insert the ID which found on device to get the distance between the hardware device and water surface to give the house owner some permission to check his house state when he is out. If the distance greater than 3 cm the application will send notification as warning.
