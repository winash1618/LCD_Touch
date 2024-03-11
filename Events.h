class Events {

    int x;
public:

    Events() {
        resetEDPins(); 
        delay(5000);
    }
    //Reset Easy Driver pins to default states
    void resetEDPins()
    {
        digitalWrite(stp, LOW);
        digitalWrite(dir, LOW);
        digitalWrite(MS1, LOW);
        digitalWrite(MS2, LOW);
        digitalWrite(EN, HIGH);
    }
    void Home()
    {
        Serial.println("Moving to home");
        digitalWrite(dir, LOW);
        while (digitalRead(LIMIT))
        {
            digitalWrite(stp, HIGH);
            delay(1);
            digitalWrite(stp, LOW);
            delay(1);
        }
        resetEDPins();
        Serial.println("Reached home");
    }

    // Move forward
    void Go(int steps)
    {
        Serial.println("Moving forward at default step mode.");
        digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
        for(x= 0; x<steps; x++)  //Loop the forward stepping enough times for motion to be visible
        {
            digitalWrite(stp,HIGH); //Trigger one step forward
            delay(1);
            digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
            delay(1);
        }
        Serial.println("Enter new option");
        Serial.println();
    }
    
    // stop
    void Stop()
    {
        Serial.println("Stop");
        resetEDPins();
    }

    
};
