<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>BrushedESC Project - ATTiny ESC</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            line-height: 1.6;
            background-color: #f9f9f9;
            color: #333;
        }
        h1, h2, h3 {
            color: #1a73e8;
        }
        img {
            max-width: 100%;
            height: auto;
            display: block;
            margin: 20px 0;
            border: 1px solid #ccc;
            border-radius: 5px;
        }
        ul {
            margin-left: 20px;
        }
        code {
            background-color: #eee;
            padding: 2px 4px;
            border-radius: 3px;
        }
        a {
            color: #1a73e8;
        }
    </style>
</head>
<body>
    <h1>BrushedESC Project - ATTiny ESC</h1>

    <h2>Project Overview</h2>
    <p>This project is a brushed DC motor ESC using an ATTiny microcontroller. It reads PWM input signals and controls motor speed and direction via an H-bridge MOSFET setup. The project demonstrates the principles of motor control, PWM-to-analog conversion, and bidirectional driving using a microcontroller.</p>

    <h2>Component Images</h2>

    <h3>1. Brushed Motor with ESC</h3>
    <img src="brushed_motor_esc.jpg" alt="Brushed Motor and ESC setup">
    <p>Shows the brushed motor connected to the ESC for testing. Filename: <code>brushed_motor_esc.jpg</code></p>

    <h3>2. ATTiny PWM Circuit</h3>
    <img src="attiny_pwm_circuit.jpg" alt="ATTiny PWM to Analog Circuit">
    <p>Photo showing ATTiny microcontroller reading PWM input and outputting control signals to the H-bridge. Filename: <code>attiny_pwm_circuit.jpg</code></p>

    <h3>3. H-Bridge MOSFET Setup</h3>
    <img src="hbridge_breadboard.jpg" alt="H-Bridge MOSFET on Breadboard">
    <p>H-bridge circuit on breadboard using 2 N-channel and 2 P-channel MOSFETs for motor control. Filename: <code>hbridge_breadboard.jpg</code></p>

    <h2>Pinouts & Wiring</h2>
    <ul>
        <li><strong>OUT1</strong>: Motor terminal 1 (connect to H-bridge output)</li>
        <li><strong>OUT2</strong>: Motor terminal 2 (connect to H-bridge output)</li>
        <li><strong>IN</strong>: PWM input from RC receiver or microcontroller</li>
        <li><strong>ATTiny</strong>: Reads PWM input and controls H-bridge MOSFETs</li>
        <li><strong>H-Bridge MOSFET</strong>: Converts ATTiny PWM signals into bidirectional motor drive</li>
    </ul>

    <h2>Understanding the H-Bridge</h2>
    <p>An H-Bridge is a circuit that allows a DC motor to be driven forward or backward by reversing the voltage across it. It is called an "H-Bridge" because the four switches and the motor layout form the shape of the letter "H".</p>

    <h3>Operation</h3>
    <ul>
        <li><strong>Forward:</strong> Activating switches 1 and 4 makes the motor spin clockwise.</li>
        <li><strong>Reverse:</strong> Activating switches 2 and 3 makes the motor spin counter-clockwise.</li>
        <li><strong>Safety:</strong> Never activate switches on the same side (1+2 or 3+4), as it creates a short circuit.</li>
    </ul>

    <h3>Using MOSFETs</h3>
    <p>In practice, switches are replaced with transistors—here, we use 2 N-channel and 2 P-channel MOSFETs. Diodes are added for protection against voltage spikes caused by the motor. The ATTiny microcontroller drives these MOSFETs based on the PWM input.</p>

    <h3>Speed Control with PWM</h3>
    <p>The motor speed is controlled using Pulse Width Modulation (PWM). PWM rapidly switches the motor voltage on and off; the duty cycle determines the effective voltage and thus the speed. Higher duty cycle = faster rotation.</p>

    <h3>Types of H-Bridge Drivers</h3>
    <p>While this project uses a breadboard H-bridge for learning, real-world applications often use integrated H-bridge ICs like <strong>L293D</strong> or <strong>DRV8873</strong> which are more compact, efficient, and feature-protected designs.</p>

    <p>Video reference: <a href="https://youtu.be/6HUs4ERsVkE" target="_blank">How H-Bridge Motor Drivers Work! (Robonyx)</a></p>

    <h2>Suggested Images to Capture</h2>
    <ul>
        <li><strong>brushed_motor_esc.jpg</strong> - Motor + ESC connections</li>
        <li><strong>attiny_pwm_circuit.jpg</strong> - ATTiny PWM wiring</li>
        <li><strong>hbridge_breadboard.jpg</strong> - H-bridge MOSFETs on breadboard</li>
    </ul>

    <h2>License</h2>
    <p>MIT License - free to use and modify.</p>
</body>
</html>
