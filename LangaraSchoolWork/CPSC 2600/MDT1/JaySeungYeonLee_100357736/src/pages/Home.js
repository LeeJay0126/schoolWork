import axios from 'axios';
import React, { useEffect, useState } from 'react';
import ImgGallery from '../components/ImgGallery';
import Spinner from '../components/Spinner';

function Home() {
  const [appState, setAppState] = useState({
    loading: false,
    images: null,
  });
  const [theme, setTheme] = useState(false);

  useEffect( () => {
    async function fetchData() {
      setAppState({loading : true});
      const apiURL = "https://jsonplaceholder.typicode.com/photos";
      const arrayList = await axios.get(apiURL);
      setTimeout(()=>{
        setAppState({loading: false, images: arrayList.data.slice(0,9)});
      }, 2000)
    }
    fetchData();
  }, [setAppState]);

  return (
    <div>
      {appState.loading ? <Spinner/> : <ImgGallery isLoading={appState.loading} images={appState.images}/>}
    </div>
  );

}
export default Home;
