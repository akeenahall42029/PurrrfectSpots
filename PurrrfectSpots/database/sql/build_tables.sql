create table users
(
    id  INT NOT NULL UNIQUE ,
    username TEXT UNIQUE,
    password TEXT NOT NULL,
    reservation_id INT , -- will delete to restructure classes later
    review_id      INT , -- will need multiple review ids, might store in an array in the user object
    primary key (id),
    foreign key (reservation_id) references reservations (id),
    foreign key (review_id) references  reviews(id) -- need

);

create table reports
(
    napSpotId   INT  NOT NULL,
    description TEXT NOT NULL,
    status      TEXT NOT NULL,
    userID      INT  NOT NULL,
    foreign key (napSpotId) references napSpots (id),
    foreign key (userID) references users (id)
);

create table reservations
(
    id        INT   NOT NULL AUTOINCREMENT, -- did this to prevent issues with creating a db insert without passing an id through before making a reservation object
    napSpotId INT  NOT NULL,
    userId    INT   NOT NULL,
    userName TEXT NOT NULL,
    startTime      INT NOT NULL, -- will be the hour
    endTime INT NOT NULL,
    status    TEXT  NOT NULL, -- will be modified by admin only, otherwise it will change when the time is up
    primary key (id),
    foreign key (napSpotId) references napSpots(id),
    foreign key (userId) references users (id)

);

create table napSpots
(
    id            INT  NOT NULL UNIQUE,
    location      TEXT NOT NULL,
    review        TEXT NOT NULL, -- might not need this
    userId        INT  NOT NULL,
    averageRating INT  NOT NULL,
    primary key (id),
    foreign key (userId) references users(id)

);

create table reviews
(
    id INT NOT NULL UNIQUE,
    userId INT NOT NULL,
    napSpotId TEXT NOT NULL, -- connects napSpots to reviews
    starRating INT NOT NULL, -- might want to constrain this to be from 0 -4
    tags TEXT NOT NULL,
    primary key (id),
    foreign key (userId) references users(id),
    foreign key (napSpotId) references napSpots(id)

);

create table admins
(
    id INT NOT NULL UNIQUE,
    name TEXT NOT NULL,
    role TEXT NOT NULL, -- this would be implemented for future developments beyond the scope of the class
    primary key (id)

);