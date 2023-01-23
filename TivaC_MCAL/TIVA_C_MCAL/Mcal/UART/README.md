
# PWM

This repo will contain PWM(Pulse-Width modulator) Driver,
all you have to do is changing the PWM_Cfg.h and PWM_Lcfg.c for you own configurations as you will see in the example below

## 🔗 Video how to use it Links
Click here to watch a Demo of the PWM Driver
[![youtube](https://img.shields.io/youtube/views/T1rNExItZcU?style=social)](https://youtu.be/-FTmAn_6DzU)


## Screenshots
![Functions API in UART](https://user-images.githubusercontent.com/63866803/214109685-59d73945-756e-4083-97cd-64e7453e70ed.png)
![UART Container](https://user-images.githubusercontent.com/63866803/214115066-524ffcdf-0596-48aa-8ad1-f2bf35443aeb.png)

## 🛠 Skills
C, Embedded C, arm architecture

## Running Tests

To run tests, just change the following variables with your own configurations in two files <br>
MCAL/UART/Dynamic/inc/UART.Cfg


```bash
#define UART_CONFIGURED_NUMBER 2
```
MCAL/UART/Dynamic/src/UART.Lcfg

```bash
const UART_ConfigType UART_Container[UART_CONFIGURED_NUMBER] = {
    {
    .uart_n = UART_NUM_5,.Uart_Mode = UARTMode_Transmit_Receive,
    .Data_Size = UARTSize_EIGHT_BITS, .parity = UARTParity_NO_PARITY,
    .StopBits_Num = UARTSTOPBIT_ONE,
    .Uart_ISRMode = {UARTISRMode_Transmit,UARTISRMode_Receive,UARTISRMode_None,UARTISRMode_None},
    .BaudRate = 9600,.endOfTransmission = 1,
    .fifo_size_rx = UART_FIFO_NOTUSED,.fifo_size_tx = UART_FIFO_NOTUSED
    },
    {
    .uart_n = UART_NUM_7,.Uart_Mode = UARTMode_Transmit_Receive,
    .Data_Size = UARTSize_EIGHT_BITS, .parity = UARTParity_NO_PARITY,
    .StopBits_Num = UARTSTOPBIT_ONE,
    .Uart_ISRMode = {UARTISRMode_Transmit,UARTISRMode_Receive,UARTISRMode_None,UARTISRMode_None},
    .BaudRate = 9600,.endOfTransmission = 0,
    .fifo_size_rx = UART_FIFO_NOTUSED,.fifo_size_tx = UART_FIFO_7_8
    }
};
};
```


## API Reference

#### All the functions you can use in PWM


| Functions | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `uart_init()` | `void` | `it initialize your UART with your configuraions`|
| `UART_Poke_to_transmit (my_uart, Bytes_Cnt)` | `void` | `it starts the transmission via my_uart channel id, if the Bytes_Cnt is 0 : it will transmit all of the queue, else it will tranmit the number of the bytes` |
| `UART_Poke_to_receive (my_uart, Bytes_Cnt)` | `uint8` | `it starts the receiving via my_uart channel id, if the Bytes_Cnt is 0 : it will receive untill the queue is full, else it will receive the number of the bytes`
| `UART_Push_to_Transmit (my_uart, x , must_be_pushed)` | `uint8` | `it updates your compare A register for the channel using a built-in method to update it with the percentage with respect to the load, high_threshold and low_threshold values`
| `UART_Pop_the_Received (my_uart, *data)` | `uint8` | `it updates your compare A register for the channel using a built-in method to update it with the percentage with respect to the load, high_threshold and low_threshold values` |

#### the only variable you need to change in PWM_Lcfg
| Variables | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `PWM_Container[ PWM_CONFIGURED_NUMBER] `      | `PWM_ConfigType` | `pwm_block (Channel Number)` |
| | |`pwmdiv (the PWM will be divided using that variable (if you don't want to use it make it 0))` |
| | |`load_value (the initial value in load register)` |
| | |`Generates_A (the initial Actions that will be generated in each event pwm(0, 2, 4, 6))` |
| | |`Generates_B (the initial Actions that will be generated in each event pwm(1, 3, 5, 7))` |
| | |`compare_a_value (the initial value in compare A register)` |
| | |`compare_b_value (the initial value in compare B register)` |
| | |`count_mode (whether the PWM will count Up/Down or just Down)` |
| | |`high_threshold (the compare registers will not exceed that value (if you don't want to use it make it 0))` |
| | |`low_threshold (the compare registers will not be lower than that value (if you don't want to use it make it 0))` |

