import praw

reddit = praw.Reddit(
    client_id="PnLdTIlLrkn5bp4Ke_UZZA",
    client_secret="BWMOHd-ZO12U7Ej7DZkJh67NObizsQ",
    user_agent="name 1.0"
)

subreddit = reddit.subreddit("whatisit").hot(limit=10)

for post in subreddit:
    print(post.title)
    print(vars(post))