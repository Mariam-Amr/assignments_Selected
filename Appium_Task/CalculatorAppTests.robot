*** Settings ***
Library    AppiumLibrary

*** Variables ***
${PLATFORM}       Android
${DEVICE_NAME}    desktop-6k39ai4\www
${APP}            \Users\www\Downloads\appium\CalculatorAppTests
${URL}            http://localhost:4723/wd/hub

*** Test Cases ***
Login With Invalid Credentials Should Fail
    [Documentation]    Test login with wrong and empty credentials.
    Open Application
    Input Text    addmin    invalid_user
    Input Text    12345     wrong_password
    Click Element  login_button
    Error Message Should Be Visible

Login With Valid Credentials Should Succeed
    [Documentation]    Test login with correct credentials.
    Open Application
    Input Text    username_field    admin
    Input Text    password_field    1234
    Click Button  login_button
    Calculator Activity Should Be Visible

*** Keywords ***
Open Application
    Open Application  ${PLATFORM}  ${DEVICE_NAME}  ${APP}  ${URL}

Error Message Should Be Visible
    Page Should Contain Element  error_message

Calculator Activity Should Be Visible
    Page Should Contain Element  calculator_activity
