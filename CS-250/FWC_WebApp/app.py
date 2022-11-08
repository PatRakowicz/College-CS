from flask import *

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.errorhandler(404)
def err404(err):
    return render_template('404.html', err=err)

app.run()

