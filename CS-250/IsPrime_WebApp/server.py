from flask import Flask, render_template

app = Flask(__name__, static_url_path='/static')


@app.route('/')
def home():
    return render_template('index.html')


@app.route('/IsPrime_WebApp/isPrime/<val>')
def isPrime(val):
    if int(val) == 2 or int(val) == 3 or int(val) == 1:
        return "<link rel='stylesheet' href='/static/style.css'>\n<h1>" + \
               val + " Prime.</h1>\n<a href='http://127.0.0.1:5000/IsPrime_WebApp/" + val + "'>Back</a>"

    if int(val) % 2 == 0 or int(val) < 2:
        return "<link rel='stylesheet' href='/static/style.css'>\n<h1>" + \
               val + " NOT Prime.</h1>\n<a href='http://127.0.0.1:5000/IsPrime_WebApp/" + val + "'>Back</a>"

    for n in range(3, int(int(val) ** 1 / 2) + 1, 2):
        if int(val) % n == 0:
            return "<link rel='stylesheet' href='/static/style.css'>\n<h1>" + \
                   val + " NOT prime.</h1>\n<a href='http://127.0.0.1:5000/IsPrime_WebApp/" + val + "'>Back</a>"

    return "<link rel='stylesheet' href='/static/style.css'>\n<h1> " + \
           val + " Prime.</h1>\n<a href='http://127.0.0.1:5000/IsPrime_WebApp/" + val + "'>Back</a>"


@app.route('/IsPrime_WebApp/<val>')
def back(val):
    return render_template('index.html')


if __name__ == "__main__":
    app.run()
