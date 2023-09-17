SCRIPT / UTILITY DESCRIPTIONS

These tools/utilities are available at codeberg.org and on the listed primary pages.

These are largely dormant, from a bygone time of the internet when such tools were
useful, but if you want to poke around them, have at it.

============================================================================

The Codeberg repos will be mirrored to Github until the end of 2023, after that,
no updates to github repos will be made. Some time after that, the code will be
removed.

Please take the time to read this helpful article from the Software Freedom
Conservancy:

https://sfconservancy.org/GiveUpGitHub/

Any use of this project's code by GitHub Copilot, past or present, is done 
without my permission. I do not consent to GitHub's use of this project's code 
in Copilot.

Version Control: https://codeberg.org/smxi/php-browser-detection

============================================================================

PHP Browser Detection

filename: browser_detection.inc

Primary home page: http://techpatterns.com/downloads/php_browser_detection.php
Support forums: http://techpatterns.com/forums/forum-11.html

A general php utility for browser / OS / Mobile / Tablet detection. 
Very robust and heavily tested in production environments. Not heavy weight 
like other php browser detectors, without sacrificing accuracy. 

This is very fast, and very efficient, utility. In continuous use and 
development for almost 15 years.

Returns either string or array data. Full explanation of output options in top
comment header of script.

There are a lot of browser detection scripts out there, some absurdly bloated
and inefficient (all we're doing is parsing the useragent string the server
returns, after all), others too simple, and prone to errors in detection.

============================================================================

PHP Language Detection

filename: language_detection.inc

Primary home page:
http://techpatterns.com/downloads/php_language_detection.php

A lightweight tool to assign browser languages. Based on the $_SERVER["HTTP_ACCEPT_LANGUAGE"]
header. 

Returns an array of the following 4 item array for each language the os supports:
1. full language abbreviation, like en-ca
2. primary language, like en
3. full language string, like English (Canada)
4. primary language string, like English

Easy to use, easy to implement, works well in conjunction with the browser
detection utility.

============================================================================

