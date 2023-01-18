from flask import *

app = Flask(__name__)


@app.route('/<name>/<num>')
def index(name, num):
    return render_template('index.html', name=name, num=num)


app.run()
