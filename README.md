# CLI-Argparser-Basic
Command line argument parser (name-value pair)

Parses command line arguments passed to the process as Name=Value pairs.
Provides:
 - Length of the entire argument, excluding null-term
 - Length of the name part, excluding null-term
 - Length of the value part, excluding null-term
 - Writes name to the output buffer, appends null-term, output buffer length limited
 - Writes value to output buffer, appends null-term, output buffer length limiter

Example input:
>argparser.exe myarg1=myval1 myarg2 myarg3= =myval4

Example output:  
Argument 0  
    Length: 13  
    Name length: 13  
    Value length: -1  
    Name: argparser.exe  

 
Argument 1  
    Length: 13  
    Name length: 6  
    Value length: 6  
    Name: myarg1  
    Value: myval1  
 
 
Argument 2  
    Length: 6  
    Name length: 6  
    Value length: -1  
    Name: myarg2  


Argument 3  
    Length: 7  
    Name length: 6  
    Value length: 0  
    Name: myarg3  


Argument 4  
    Length: 7  
    Name length: 0  
    Value length: 6  
    Value: myval4  
