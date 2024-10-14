# ATM State Machine Requirements

## Initial State
- **Off**: The ATM starts in an ‘Off’ state.

## Startup and Self-Test
- **Turn On/Startup**: The ATM transitions from ‘Off’ to ‘Self Test’.
- **Self Test**: The ATM performs a self-test to ensure all components are functioning.

## Idle State
- **Idle**: If the self-test is successful, the ATM enters an ‘Idle’ state, waiting for customer interaction.

## Customer Interaction
- **Card Inserted**: When a customer inserts a card, the ATM moves to ‘Authenticate Customer’.
- **Authentication**: The ATM verifies the customer’s credentials.
- **Transaction Processing**: Upon successful authentication, the customer can perform transactions.

## Transaction Completion
- **Eject Card/Cancel Transaction**: The ATM should allow customers to cancel transactions or eject their cards, returning to ‘Idle’.
- **Completion**: After a successful transaction, the ATM returns to ‘Idle’.

## Error Handling
- **Failure**: If any failure occurs during self-test, maintenance, or transaction processing, the ATM transitions to ‘Out of Service’.
- **Maintenance Mode**: The ATM can enter maintenance mode from ‘Idle’ or ‘Serving Customer’ states if needed.





# ATM State Transition Table

| **Current State**     | **Event**            | **Action**                | **Next State**         |
|-----------------------|----------------------|---------------------------|------------------------|
| Off                   | Turn On/Startup      | Perform Self Test         | Self Test              |
| Self Test             | Self Test Successful | None                      | Idle                   |
| Self Test             | Self Test Failure    | Display Error, Shut Down  | Out of Service         |
| Idle                  | Card Inserted        | Read Card                 | Ready to Serve         |
| Ready to Serve        | Authentication Fail  | Eject Card, Display Error | Idle                   |
| Ready to Serve        | Authentication Pass  | None                      | Serving Customer       |
| Serving Customer      | Transaction Success  | Complete Transaction      | Idle                   |
| Serving Customer      | Transaction Fail     | Display Error, Eject Card | Idle                   |
| Serving Customer      | Cancel Transaction   | Eject Card                | Idle                   |
| Idle/Serving Customer | Enter Maintenance    | Enter Maintenance Mode    | Maintenance            |
| Maintenance           | Maintenance Complete | None                      | Idle                   |
| Self Test/Maintainence/Transaction Processing| Failure              | Display Error, Shut Down  | Out of Service         |
   


