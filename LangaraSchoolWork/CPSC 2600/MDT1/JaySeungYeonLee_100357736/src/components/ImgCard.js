import React from 'react'

const ImgCard = (props) => {
    const { item } = props;
    return (
              <div className="col s12 m4">
                <div className="card medium">
                  <div className="card-image">
                    <img alt={item.title} src={item.thumbnailUrl}/>
                    <span className="card-title">{item.title}</span>
                  </div>
                  <div className="card-content">
                    <h6>Album ID: {item.albumId}</h6>
                    <h6>ID: {item.id}</h6>
                  </div>
                  <div className="card-action">
                    <a href={item.url}>{item.url}</a>
                  </div>
                </div>
              </div>
    )
}

export default ImgCard
