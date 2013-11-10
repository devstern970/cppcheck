import os
import sys


def readdate(data):
    datepos = -1
    if data[:5] == 'DATE ':
        datepos = 0
    else:
        datepos = data.find('\nDATE ')
        if datepos >= 0:
            datepos = datepos + 1

    if datepos < 0:
        return None

    datestr = ''
    datepos = datepos + 5
    while True:
        if datepos >= len(data):
            return None
        d = data[datepos]
        if d >= '0' and d <= '9':
            datestr = datestr + d
        elif d == '\n':
            if len(datestr) == 8:
                return datestr[:4] + '-' + datestr[4:6] + '-' + datestr[6:]
            return None
        elif d != ' ' and d != '-':
            return None
        datepos = datepos + 1

path = '.'
if len(sys.argv) == 2:
    path = sys.argv[1]

mainpage = open(path + '/daca2.html', 'wt')
mainpage.write('<!DOCTYPE html>\n')
mainpage.write('<html lang="en">\n')
mainpage.write('<head>\n')
mainpage.write('<meta charset="utf-8">\n')
mainpage.write('<title>DACA2</title>\n')
mainpage.write('<style>td { font-size: 0.9em; } td + td { padding-left: 6em; }</style>\n')
mainpage.write('</head>\n')
mainpage.write('<body>\n')
mainpage.write('<h1>DACA2</h1>\n')
mainpage.write(
    '<p>Results when running latest (git head) Cppcheck on Debian.</p>\n')
mainpage.write(
    '<p>For performance reasons the analysis is limited. Files larger than 100kb are skipped. If analysis of a file takes more than 10 minutes it may be stopped.</p>\n')
mainpage.write('<p>The hardware running the analysis is a Raspberry PI.</p>\n')
mainpage.write('<table>\n')
mainpage.write(
    '<tr><td>Name</td><td>Date</td></tr>\n')

lastupdate = None
recent = []

daca2 = os.path.expanduser('~/daca2/')
for lib in range(2):
    for a in "0123456789abcdefghijklmnopqrstuvwxyz":
        if lib == 1:
            a = "lib" + a
        if os.path.isfile(daca2 + a + '/results.txt'):
            f = open(daca2 + a + '/results.txt', 'rt')
            data = f.read()
            f.close()

            datestr = readdate(data)
            if datestr:
                if not lastupdate or datestr > lastupdate:
                    lastupdate = datestr
                    recent = []
                if datestr == lastupdate:
                    recent.append(a)

            mainpage.write(
                '<tr><td><a href="daca2-' + a + '.html">' + a + '</a></td><td>' + datestr + '</td></tr>\n')

            data = data.replace('&', '&amp;')
            data = data.replace('<', '&lt;')
            data = data.replace('>', '&gt;')
            data = data.replace('\n', '\n')

            f = open(path + '/daca2-' + a + '.html', 'wt')
            f.write('<!DOCTYPE html>\n')
            f.write('<html lang="en">\n')
            f.write('<head>\n')
            f.write('<meta charset="utf-8">\n')
            f.write('<title>DACA2 - ' + a + '</title>\n')
            f.write('</head>\n')
            f.write('<body>\n')
            f.write('<h1>DACA2 - ' + a + '</h1>')
            f.write('<pre>\n' + data + '</pre>\n')
            f.write('</body>\n')
            f.write('</html>\n')
            f.close()

mainpage.write('</table>\n')

if lastupdate:
    mainpage.write('<p>Last update: ' + lastupdate + '</p>')
    allrecent = ''
    for r in recent:
        allrecent = allrecent + '<a href="daca2-' + r + '.html">' + r + '</a>'
    mainpage.write('<p>Most recently updated: ' + allrecent + '</p>')

mainpage.write('</body>\n')
mainpage.write('</html>\n')
