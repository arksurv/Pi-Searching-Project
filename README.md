# Pi Searching Project
### A project to search for the strings "1234567890" and "0123456789" in the decimal digits of Pi.
Sample of Pi not provided; log files from running the program on various different amounts of digits of Pi are provided in the output_xyz_##b files, where xyz refers to which sequence was searched for (either 123... or 012...) and ## refers to the amount of billions of digits of Pi searched (provided are files for 1 billion, 5 billion, 10 billion, and 25 billion). For the files run on the higher digits of Pi, only more exact matches were recorded to avoid an overabundance of matches.

### If you would like a sample of Pi to run the searching program on yourself:
- Consider downloading a billion digits of pi here: https://stuff.mit.edu/afs/sipb/contrib/pi/pi-billion.txt <br>
- Or, download y-cruncher to calculate some digits yourself: http://numberworld.org/y-cruncher/ <br>
- Or, download a sample from Google's 100 trillion digits of Pi here and uncompress using y-cruncher: https://storage.googleapis.com/pi100t/index.html (very large files; each contains 100 billion digits, you can extract a variable amount of digits using y-cruncher's interface)

### If you're here for the results, here are the major findings from the first 25 billion digits:
#### 1234567890 can be found in two places:
- Digits: 7997135199-7997135208
- Digits: 18102347340-18102347349

#### 0123456789 can be found in one place:
- Digits: 17387594882-17387594891
#### Note: these digit ranges are inclusive and offset in two ways. The first digit is considered to be digit 1 rather than digit 0, and the decimal point is counted as a digit. For instance, if you wanted to fetch these results from Google's Pi fetching API, you should subtract 2, as the API considers the first digit to be digit 0 and does not include the decimal point as a digit.

### The findings proven using Google's Pi request API:
- 1234567890 #1: https://api.pi.delivery/v1/pi?start=7997135197&numberOfDigits=10
- 1234567890 #2: https://api.pi.delivery/v1/pi?start=18102347338&numberOfDigits=10
- 0123456789 #1: https://api.pi.delivery/v1/pi?start=17387594880&numberOfDigits=10

### Crediting:
If you use my program or findings in any way, please link back to this Repository if possible. You may modify the program in any way you wish and even publish your own modified version as long as it is freely available and provides a link or citation back to this Repository.

### Final Note:
I don't believe I will be searching much further than 25 billion digits given my current computational power (only my own PC) and my available storage space (only willing to use around 100GB, and only temporarily). If you would like to use this hacked together program to search further, or to search for some other string of digits, please do so! Please also feel free to inform me of your results (perhaps in an Issue, or in a Pull Request that modifies this README to include your results).
