create table users
(
    id             INT  NOT NULL UNIQUE,
    name           TEXT NOT NULL,
    reservation_id INT  NOT NULL,
    review_id      INT  NOT NULL,
    primary key (id),
    foreign key (id) references report (userId),
    foreign key (reservation_id) references reservations (id)

)

create table reports
(
    napSpotId   INT  NOT NULL,
    description TEXT NOT NULL,
    status      TEXT NOT NULL,
    userID      INT  NOT NULL,
    foreign key (napSpotId) references napSpots (id),
    foreign key (userID) references users (id)
)

create table reservations
(
    id        INT   NOT NULL UNIQUE,
    napSpotId TEXT  NOT NULL,
    userId    INT   NOT NULL,
    time      INT NOT NULL, -- will be in minutes
    status    TEXT  NOT NULL,
    primary key (id),
    foreign key (id) references users(reservation_id),
    foreign key (userId) references users (id)

)

create table napSpots
(
    id            INT  NOT NULL UNIQUE,
    location      TEXT NOT NULL,
    review        TEXT NOT NULL, -- how do I link the contents from the review table to this table
    userId        INT  NOT NULL,
    averageRating INT  NOT NULL,
    primary key (id),
    foreign key (id) references reports(napSpotId),
    foreign key (userId) references users(id)


)

create table reviews
(
    id INT NOT NULL UNIQUE,
    userId INT NOT NULL,
    location TEXT NOT NULL,
    starRating INT NOT NULL, -- might want to constrain this to be from 0 -4
    tags TEXT NOT NULL,
    primary key (id),
    foreign key (userId) references users(id)

)

create table admins
(
    id INT NOT NULL UNIQUE,
    name TEXT NOT NULL,
    role TEXT NOT NULL

)