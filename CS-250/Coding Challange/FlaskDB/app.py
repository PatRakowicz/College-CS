from flask import Flask
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
db = SQLAlchemy(app)


class Role(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    role_type = db.Column(db.String(40))
    users = db.relationship('User', backref='role')


class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(80))
    role_id = db.Column(db.Integer, db.ForeignKey('role.id'))


# @app.route('/')
# def index():
#     users = User.query.all()
#     s = ''
#     for u in users:
#         s += users

app.app_context().push()

if __name__ == '__main__':
    app.run()
