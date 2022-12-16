from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_login import *

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
db = SQLAlchemy(app)


class User(UserMixin, db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(20))
    password = db.Column(db.String(80))


app.config['SECRET_KEY'] = 'Secret Key'
login_manager = LoginManager(app)
login_manager.init_app(app)


@login_manager.user_loader
def load_user(uid):
    user = User.query.get(uid)
    return user


@app.route('/login')
def login():
    user = User.query.filter_by(username='fred42').first()
    login_user(user)
    return user.username


@app.route('/logout')
def logout():
    logout_user()
    return 'Logged Out'


@app.route('/secret')
@login_required
def secret():
    return current_user.name + ' Secret message '


app.app_context().push()
if __name__ == '__main__':
    app.run()
