# Arduino Button Ladder
<p align="center">
It is an utility class for Switches,<br/>
in this case are Push-Button. 
<br/>With debouce sistem based on time that is configurable <br/>
Very simple to use :   <br/>
You have to pass a <em> method(int val) </em> do you prefer to the constructor</br>
The <em>val</em> parameter give you the value in voltage read by the analog input<br/>
</p>


<div id ="example">
<p>
<code>
  ButtonLadder* butt_ladder = new ButtonLadder(PIN_LADDER, exploreVoltRange);
</code>
<br/>
</p>
</div>

<p>
Check the example in the ButtonLadderExample folder
</p>

<p align="center">
  <img src="ButtonLadder.png"/>
</p>
