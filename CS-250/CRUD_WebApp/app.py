from flask import *
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__, static_url_path='/static')
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
db = SQLAlchemy(app)


class Fruit(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(100))
    color = db.Column(db.String(100))


@app.route('/')
def home():
    return render_template('home.html')


@app.route('/create', methods=['POST', 'GET'])
def create():
    if request.method == 'POST':
        fruit = request.form["fruit"]
        color = request.form["color"]

        _entry = Fruit(name=fruit, color=color)

        db.session.add(_entry)
        db.session.commit()

        return redirect('read')
    else:
        return render_template('create.html')


@app.route('/read')
def read():
    list = Fruit.query.all()
    return render_template('read.html', list=list)


@app.route('/update/<id>', methods=['POST', 'GET'])
def update(id):
    target = Fruit.query.filter_by(id=id).first()
    if request.method == 'POST':
        target.name = request.form['fruit']
        target.color = request.form['color']

        db.session.commit()

        return redirect('/read')
    else:
        return render_template('update.html', fruit=target.name, color=target.color, id=id)


@app.route('/delete/<id>')
def delete(id):
    target = Fruit.query.filter_by(id=id).first()
    db.session.delete(target)
    db.session.commit()
    return redirect('/read')


@app.errorhandler(404)
def err404(err):
    return render_template('404.html', err=err)


app.app_context().push()

if __name__ == "__main__":
    app.run()
