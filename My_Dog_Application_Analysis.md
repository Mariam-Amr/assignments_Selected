# My Dog Application Analysis

## Requirements Analysis and Bug Identification

1. **Registration and Dog Info**:
   - **Requirement**: Register with email, password, phone number (with verification), and fill in dog info (Name, Age, Type).
   - **Potential Bugs**:
     - Missing validation for email format, password strength, and phone number format.
     - No mention of handling duplicate registrations.
     - No mention of what happens if the dog info is incomplete or incorrect.

2. **Calling the Dog via Bluetooth**:
   - **Requirement**: Call the dog via voice through the app while connected via Bluetooth, with the dog within 100m range.
   - **Potential Bugs**:
     - Bluetooth range is specified as 10m, but the requirement mentions 100m range, which is inconsistent.
     - No mention of handling scenarios where the Bluetooth connection is lost or weak.
     - No details on how the voice call is initiated and managed.

3. **Getting Dog Location via GPS**:
   - **Requirement**: Get the dog's location via the mobile app.
   - **Potential Bugs**:
     - No mention of how frequently the GPS location is updated (time interval).
     - No details on handling GPS signal loss or inaccuracies.
     - Privacy concerns regarding sharing of location data.

4. **Notification for Feeding Time**:
   - **Requirement**: Get notified by “Dog Should Eat” at selected time intervals (minimum 3 hours).
   - **Potential Bugs**:
     - No mention of how notifications are managed (push notifications, in-app alerts).
     - No details on handling changes to the time interval settings.

## Test Cases

1. **Registration and Dog Info**:
   - **Test Case 1**: Verify that the user can register with a valid email, password, and phone number.
   - **Test Case 2**: Verify that the app validates the email format, password strength, and phone number format.
   - **Test Case 3**: Verify that the user cannot register with an already registered email or phone number.
   - **Test Case 4**: Verify that the user must fill in all required dog info fields (Name, Age, Type) to complete registration (No empty fileds).

2. **Calling the Dog via Bluetooth**:
   - **Test Case 1**: Verify that the app can connect to the Dog Recall Device via Bluetooth within a 10m range.
   - **Test Case 2**: Verify that the app can initiate a voice call to the dog when connected via Bluetooth.
   - **Test Case 3**: Verify that the app handles scenarios where the Bluetooth connection is lost or weak.
   - **Test Case 4**: Verify that the app displays an error message if the dog is out of Bluetooth range.

3. **Getting Dog Location via GPS**:
   - **Test Case 1**: Verify that the app can retrieve the dog's location via GPS.
   - **Test Case 2**: Verify that the GPS location is updated at regular intervals.
   - **Test Case 3**: Verify that the app handles scenarios where the GPS signal is lost or inaccurate.
   - **Test Case 4**: Verify that the app securely stores location data.

4. **Notification for Feeding Time**:
   - **Test Case 1**: Verify that the user can set a feeding time interval (minimum 3 hours).
   - **Test Case 2**: Verify that the app sends notifications at the selected time intervals.
   - **Test Case 3**: Verify that the user can change the feeding time interval settings.

