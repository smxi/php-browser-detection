<?php
/**
Script Name: php_language_detection.inc
Date: 2015-07-30
Version: 0.4.0

This script is a lightweight tool to detect and handle user languages based
on the $_SERVER["HTTP_ACCEPT_LANGUAGE"] data the browser sends to the server.

Author: Harald Hope, Website: http://techpatterns.com/
Script Source URI: http://techpatterns.com/downloads/php_language_detection.php
Copyright (C) 2004-2015

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

Get the full text of the GPL here: http://www.gnu.org/licenses/gpl.txt

Language reference resources:
http://www.science.co.il/Language/Locale-codes.asp
https://developer.chrome.com/webstore/i18n

Coding conventions:
Indentation: tabs; variable/function names: clear, explicit, easy to read

CHANGES:
0.4.0 2015-07-30 - Added languages to list, thanks hl2guide; cleaned up code/comments;
                   got rid of pointless second loop;
0.3.6 2008-12-08 - added possible $feature values to comment header section

OPTIONS AND USE: 
Script is currently set to accept 2 parameters, triggered by $feature value.
for example, get_languages( 'data' ):
$feature - parameters:
1. 'header' - sets header values, for redirects etc. No data is returned
2. 'data' - for language data handling, ie for stats, etc.
	Returns an array of the following 4 item array for each language the os supports:
	1. full language abbreviation, like en-ca
	2. primary language, like en
	3. full language string, like English (Canada)
	4. primary language string, like English

SETUP:
Note that the script is set up with some sample actions, that of course
you will want to alter to fit your needs:

Look below for (about line 116):
elseif ( $feature == 'header' ) {

Then change those actions to use the paths you want for redirects etc.

For basic testing, pre production, you can use the debuggers to make sure
everything is working the way you expected.

**/

// choice of redirection header or just getting language data
// to call this you only need to use the $feature parameter
function get_languages( $feature, $spare='' )
{
	// initialize variables
	$a_languages = load_language_data();
	$index = '';
	$complete = '';
	$b_found = false;// set to default value
	//prepare user language array
	$a_user_languages = array();
	// debuggers, set to true to trigger action:
	$b_debugger_1 = false; // print out return array
	$b_debugger_2 = false; // set fake data values
	
	//check to see if language is set
	if ( isset( $_SERVER["HTTP_ACCEPT_LANGUAGE"] ) ) {
		$languages = strtolower( $_SERVER["HTTP_ACCEPT_LANGUAGE"] );
		if ($b_debugger_2 === true){
			$languages = ' fr-ch;q=0.3, da, en-us;q=0.8, en;q=0.5, fr;q=0.3';
		}
		// need to remove spaces from strings to avoid error
		$languages = str_replace( ' ', '', $languages );
		$a_languages_working = explode( ',', $languages );
		//$a_languages_working = explode( ",", $test);// this is for testing purposes only
		foreach ( $a_languages_working as $language_list ) {
			// pull out the language, place languages into array of full and primary
			// string structure:
			$a_temp = array();
			// slice out the part before ; on first step, the part before - on second, place into array
			$a_temp[0] = substr( $language_list, 0, strcspn( $language_list, ';' ) );//full language
			$a_temp[1] = substr( $language_list, 0, 2 );// cut out primary language
			// then we'll see if that array key exists in the language array, and pack the rest of the values
			if ( array_key_exists($a_temp[0], $a_languages ) === true ) {
				// complete language, like english (canada)
				$a_temp[2] = $a_languages[$a_temp[0]];
				// extract working language, like english
				$a_temp[3] = substr( $a_temp[2], 0, strcspn( $a_temp[2], ' (' ) );
			}
			else {
				$a_temp[2] = '';
				$a_temp[3] = '';
			}
			//place this array into main $a_user_languages language array
			$a_user_languages[] = $a_temp;
		}
	}
	// if no languages found
	else {
		$a_user_languages[0] = array( '','','','' ); //return array with empty values.
	}
	if ( $b_debugger_1 === true ){
		echo '<pre>';
		print_r($a_user_languages);
		echo '</pre>';
	}
	// return parameters
	if ( $feature == 'data' ) {
		return $a_user_languages;
	}
	// this is just a sample, replace target language and file names with your own.
	elseif ( $feature == 'header' ) {
		// get default primary language, the first one in array that is
		switch ( $a_user_languages[0][1] ) {
			case 'en':
				$location = 'english.php';
				$b_found = true;
				break;
			case 'sp':
				$location = 'spanish.php';
				$b_found = true;
				break;
			default:
				break;
		}
		if ( $b_found === true ) {
			header("Location: $location");
		}
		// make sure you have a default page to send them to
		else {
			header("Location: default.php");
		}
	}
}

function load_language_data()
{
	/**
	pack abbreviation/language array
	important note: you must have the default language as the last item in each major language, after all the
	en-ca type entries, so en would be last in that case
	**/
	$a_languages = array(
	'af' => 'Afrikaans',
	'sq' => 'Albanian',
	'am' => 'Amharic',
	'ar-dz' => 'Arabic (Algeria)',
	'ar-bh' => 'Arabic (Bahrain)',
	'ar-eg' => 'Arabic (Egypt)',
	'ar-iq' => 'Arabic (Iraq)',
	'ar-jo' => 'Arabic (Jordan)',
	'ar-kw' => 'Arabic (Kuwait)',
	'ar-lb' => 'Arabic (Lebanon)',
	'ar-ly' => 'Arabic (Libya)',
	'ar-ma' => 'Arabic (Morocco)',
	'ar-om' => 'Arabic (Oman)',
	'ar-qa' => 'Arabic (Qatar)',
	'ar-sa' => 'Arabic (Saudi Arabia)',
	'ar-sy' => 'Arabic (Syria)',
	'ar-tn' => 'Arabic (Tunisia)',
	'ar-ae' => 'Arabic (U.A.E.)',
	'ar-ye' => 'Arabic (Yemen)',
	'ar' => 'Arabic',
	'hy' => 'Armenian',
	'as' => 'Assamese',
	'az' => 'Azeri',
	'eu' => 'Basque',
	'be' => 'Belarusian',
	'bn' => 'Bengali',
	'bs' => 'Bosnian',
	'bg' => 'Bulgarian',
	'my' => 'Burmese',
	'ca' => 'Catalan',
	'zh-cn' => 'Chinese (China)',
	'zh-hk' => 'Chinese (Hong Kong SAR)',
	'zh-mo' => 'Chinese (Macau SAR)',
	'zh-sg' => 'Chinese (Singapore)',
	'zh-tw' => 'Chinese (Taiwan)',
	'zh' => 'Chinese',
	'hr' => 'Croatian',
	'cs' => 'Czech',
	'da' => 'Danish',
	'div' => 'Divehi',
	'nl-be' => 'Dutch (Belgium)',
	'nl' => 'Dutch (Netherlands)',
	'en-au' => 'English (Australia)',
	'en-bz' => 'English (Belize)',
	'en-ca' => 'English (Canada)',
	'en-cb' => 'English (Caribbean)',
	'en-in' => 'English (India)',
	'en-ie' => 'English (Ireland)',
	'en-jm' => 'English (Jamaica)',
	'en-nz' => 'English (New Zealand)',
	'en-ph' => 'English (Philippines)',
	'en-za' => 'English (South Africa)',
	'en-tt' => 'English (Trinidad)',
	'en-gb' => 'English (United Kingdom)',
	'en-us' => 'English (United States)',
	'en-zw' => 'English (Zimbabwe)',
	'en' => 'English',
	'us' => 'English (United States)',
	'et' => 'Estonian',
	'fo' => 'Faeroese',
	'fa' => 'Farsi',
	'fi' => 'Finnish',
	'fr-be' => 'French (Belgium)',
	'fr-ca' => 'French (Canada)',
	'fr-lu' => 'French (Luxembourg)',
	'fr-mc' => 'French (Monaco)',
	'fr-ch' => 'French (Switzerland)',
	'fr' => 'French (France)',
	'mk' => 'FYRO Macedonian',
	'gd' => 'Gaelic',
	'ka' => 'Georgian',
	'de-at' => 'German (Austria)',
	'de-li' => 'German (Liechtenstein)',
	'de-lu' => 'German (Luxembourg)',
	'de-ch' => 'German (Switzerland)',
	'de' => 'German (Germany)',
	'el' => 'Greek',
	'gn' => 'Guarani (Paraguay)',
	'gu' => 'Gujarati',
	'he' => 'Hebrew',
	'hi' => 'Hindi',
	'hu' => 'Hungarian',
	'is' => 'Icelandic',
	'id' => 'Indonesian',
	'it-ch' => 'Italian (Switzerland)',
	'it' => 'Italian (Italy)',
	'ja' => 'Japanese',
	'kn' => 'Kannada',
	'ks' => 'Kashmiri',
	'kk' => 'Kazakh',
	'km' => 'Khmer',
	'kok' => 'Konkani',
	'ko' => 'Korean',
	'kz' => 'Kyrgyz',
	'lo' => 'Lao',
	'la' => 'Latin',
	'lv' => 'Latvian',
	'lt' => 'Lithuanian',
	'ms-bn' => 'Malay (Brunei)',
	'ms-my' => 'Malay (Malaysia)',
	'ms' => 'Malay',
	'ml' => 'Malayalam',
	'mt' => 'Maltese',
	'mi' => 'Maori',
	'mr' => 'Marathi',
	'mn' => 'Mongolian (Cyrillic)',
	'ne' => 'Nepali (India)',
	'nb-no' => 'Norwegian (Bokmal)',
	'nn-no' => 'Norwegian (Nynorsk)',
	'no' => 'Norwegian (Bokmal)',
	'or' => 'Oriya',
	'pl' => 'Polish',
	'pt-br' => 'Portuguese (Brazil)',
	'pt' => 'Portuguese (Portugal)',
	'pa' => 'Punjabi',
	'rm' => 'Rhaeto-Romanic',
	'ro-md' => 'Romanian (Moldova)',
	'ro' => 'Romanian',
	'ru-md' => 'Russian (Moldova)',
	'ru' => 'Russian',
	'sa' => 'Sanskrit',
	'sr' => 'Serbian',
	'sd' => 'Sindhi',
	'si' => 'Sinhala',
	'sk' => 'Slovak',
	'ls' => 'Slovenian',
	'so' => 'Somali',
	'sb' => 'Sorbian',
	'es-ar' => 'Spanish (Argentina)',
	'es-bo' => 'Spanish (Bolivia)',
	'es-cl' => 'Spanish (Chile)',
	'es-co' => 'Spanish (Colombia)',
	'es-cr' => 'Spanish (Costa Rica)',
	'es-do' => 'Spanish (Dominican Republic)',
	'es-ec' => 'Spanish (Ecuador)',
	'es-sv' => 'Spanish (El Salvador)',
	'es-gt' => 'Spanish (Guatemala)',
	'es-hn' => 'Spanish (Honduras)',
	'es-mx' => 'Spanish (Mexico)',
	'es-ni' => 'Spanish (Nicaragua)',
	'es-pa' => 'Spanish (Panama)',
	'es-py' => 'Spanish (Paraguay)',
	'es-pe' => 'Spanish (Peru)',
	'es-pr' => 'Spanish (Puerto Rico)',
	'es-us' => 'Spanish (United States)',
	'es-uy' => 'Spanish (Uruguay)',
	'es-ve' => 'Spanish (Venezuela)',
	'es' => 'Spanish (Traditional Sort)',
	'sx' => 'Sutu',
	'sw' => 'Swahili',
	'sv-fi' => 'Swedish (Finland)',
	'sv' => 'Swedish',
	'syr' => 'Syriac',
	'tg' => 'Tajik',
	'ta' => 'Tamil',
	'tt' => 'Tatar',
	'te' => 'Telugu',
	'th' => 'Thai',
	'bo' => 'Tibetan',
	'ts' => 'Tsonga',
	'tn' => 'Tswana',
	'tr' => 'Turkish',
	'tk' => 'Turkmen',
	'uk' => 'Ukrainian',
	'ur' => 'Urdu',
	'uz' => 'Uzbek',
	'vi' => 'Vietnamese',
	'cy' => 'Welsh',
	'xh' => 'Xhosa',
	'yi' => 'Yiddish',
	'zu' => 'Zulu' );

	return $a_languages;
}
?>